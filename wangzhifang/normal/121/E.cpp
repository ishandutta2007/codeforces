#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
const int lcn[]={4,7,44,47,74,77,444,447,474,477,744,747,774,777,4444,4447,4474,4477,4744,4747,4774,4777,7444,7447,7474,7477,7744,7747,7774,7777};
struct block{
    int tong[10020];
    int tag;
    inline void update(int a,int b){
        tong[a] --;
        tong[b] ++;
    }
    inline void put(int x){
        tong[x] ++;
    }
    inline int get(){
        register int ret=0;
        for(int i:lcn)
        	if(i-tag>=0)
            ret+=tong[i-tag];
        return ret;
    }
    inline void plus(int x){
        tag += x;
    }
};
block blocks[5001];
int size_of_blocks;
inline block& _block(int num){
    return blocks[num/size_of_blocks];
}
int a[100001];
bool check[10020];
int main(){
    int n,m,x,i,y,z;
    for(int i:lcn)
        check[i]=1;
    char c;
    scanf("%d%d",& n,& m);
    size_of_blocks=5*int(sqrt(n));
    for(i = 1; i <= n; i ++){
        scanf("%d",a+i);
        blocks[i/size_of_blocks].put(a[i]);
    }
    for(i = 1; i <= m; i ++){
        scanf("\n%c%*s",& c);
        if(c == 'a'){
            scanf("%d%d%d",& x,& y,& z);
            for(; x % size_of_blocks && x <= y; x ++){
                _block(x).update(a[x],a[x]+z);
                a[x] += z;
            }
            for(; (y+1) % size_of_blocks && x <= y; y --){
                _block(y).update(a[y],a[y]+z);
                a[y] += z;
            }
            for(; x <= y; x+=size_of_blocks)
                _block(x).plus(z);
        }
        else{
            scanf("%d%d",& x,& y);
            z=0;
            for(; x % size_of_blocks && x <= y; x ++)
                z += check[_block(x).tag+a[x]];
            for(; (y+1) % size_of_blocks && x <= y; y --)
                z += check[_block(y).tag+a[y]];
            for(; x <= y; x+=size_of_blocks)
                z += _block(x).get();
            printf("%d\n",z);
        }
    }
    return 0;
}