#include<stdio.h>
#include<string.h>
#include<list>

using namespace std;

int N;
char ppp[50001];
list<char> A;
list<char>::iterator l,r,st;

int main(){
//  freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    int i,j,cnt;
    scanf("%s",ppp);
    N=strlen(ppp);

    for(i=0;i<N;i++)A.push_back(ppp[i]);

    for(i=1;2*i<=N;i++){
        l=r=A.begin();
        for(j=0;j<i;j++,r++);
        cnt=i;
        while(r!=A.end()){
            if(*l!=*r){
                cnt=i;
                l++,r++;
                continue;
            }
            else{
                if(cnt==i)  st=l;
                --cnt;
                l++,r++;
                if(cnt==0){
                    A.erase(st,l);
                    N-=i;
                    cnt=i;
                }
            }
        }
    }
    for(st=A.begin();st!=A.end();st++){
        printf("%c",*st);
    }
    return 0;
}