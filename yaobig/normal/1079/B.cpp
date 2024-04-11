#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn 100
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

char s[105];
char t[10][30];

int main()
{
    scanf("%s",s);
    int n=strlen(s);
    int r;
    for(r=1;r*20<n;r++);
    int c=(n+r-1)/r;
    int bu=r*c-n;
    int st=0;
    printf("%d %d\n",r,c);
    rep(i,1,r)
    {
        if(i<=r-bu)
        {
            rep(i,0,c-1) printf("%c",s[st+i]);
            printf("\n");
            st+=c;
        }
        else
        {
            rep(i,0,c-2) printf("%c",s[st+i]);
            printf("*");
            printf("\n");
            st+=c-1;
        }

    }

    return 0;
}