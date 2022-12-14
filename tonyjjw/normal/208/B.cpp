#include<stdio.h>
#include<queue>
#define MAX(a,b)((a)>(b)?(a):(b))

using namespace std;

const int MN = 52 + 1;

int N;
char str[MN][3];

bool V[MN][MN][MN][MN];

struct QUE{
    int n,a,b,c;
}H;

queue<QUE> Q;

void pushQ(int n,int a,int b,int c){
    if(V[n][a][b][c])return;
    QUE A={n,a,b,c};
    Q.push(A);
    V[n][a][b][c]=1;
}

bool chk(int a,int b){
    if(a<=0 || b<=0)return false;
    return (str[a][0]==str[b][0])||(str[a][1]==str[b][1]);
}

int main(){
//    freopen("input","r",stdin);
    int i;
    scanf("%d",&N);
    for(i=1;i<=N;i++)scanf("%s",str[i]);
    pushQ(N,MAX(0,N-2),MAX(0,N-1),N);
    while(!Q.empty()){
        H=Q.front();
        if(H.n==1)break;
        Q.pop();
        if(H.n>3 && chk(H.c,H.n-3)){
            pushQ(H.n-1,H.c,H.a,H.b);
        }
        if(H.n>1 && chk(H.c,H.b)){
            pushQ(H.n-1,MAX(0,H.n-3),H.a,H.c);
        }
    }
    if(!Q.empty()){
        puts("YES");
        return 0;
    }
    puts("NO");
    return 0;
}