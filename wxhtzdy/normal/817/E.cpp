#include <bits/stdc++.h>
using namespace std;

const int N=3000000;

struct Node{
    int id,sz,ch[2];
    Node(){}
}trie[N];

int tsz;
void Insert(int x){
    int j=0;
    for(int i=(1<<29);i>0;i>>=1){
        int c=((x&i)>0?1:0);
        if(!trie[j].ch[c])trie[j].ch[c]=++tsz;
        j=trie[j].ch[c];
        trie[j].sz++;
    }
}

void Remove(int x){
    int j=0;
    for(int i=(1<<29);i>0;i>>=1){
        int c=((x&i)>0?1:0);
        j=trie[j].ch[c];
        trie[j].sz--;
    }
}

int Get(int x,int y){
    int j=0,cnt=0,z=x^y;
    for(int i=(1<<29);i>0;i>>=1){
        if(y&i)cnt+=trie[trie[j].ch[(x&i)>0?1:0]].sz;
        j=trie[j].ch[(z&i)>0?1:0];
        if(!j)break;
    }
    return cnt;
}

int main(){
    int q;scanf("%i",&q);
    while(q--){
        int type;scanf("%i",&type);
        if(type==1){
            int x;scanf("%i",&x);
            Insert(x);
        }
        if(type==2){
            int x;scanf("%i",&x);
            Remove(x);
        }
        if(type==3){
            int x,y;scanf("%i%i",&x,&y);
            printf("%i\n",Get(x,y));
        }
    }
    return 0;
}