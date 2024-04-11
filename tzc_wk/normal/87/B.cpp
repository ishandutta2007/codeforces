#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=500100;
const long long mod=1e9+7;
int n,m,q,k,flag,x,f,y,p;
int ans,tmp,cnt;
int a[maxn],c[maxn];
char s[maxn],ss[maxn],sss[maxn];
map<string,int> mp;
string str1,str2;
int Case=0;
int main(){
//	freopen("87B-Input.txt","r",stdin);
//	freopen("87B-output.txt","w",stdout);
    int T;
    while(scanf("%d",&n)!=EOF){
    	Case++;
        mp.clear();
        mp["void"]=1;
        for(int i=0;i<n;i++){
            scanf("%s",s);
            if(strcmp(s,"typedef")==0){
                scanf("%s %s",ss,sss);
                int l=strlen(ss);
                int i=0;
                int ans=0,cnt=0;
                str1="";
                for(int i=0;i<l;i++)
                {
                    if(ss[i]=='&') ans--;
                    else if(ss[i]=='*') ans++;
                    else str1+=ss[i];
                }
                cnt=mp[str1];
                if(cnt>0) cnt+=ans;
                else cnt=0;
                mp[(string)sss]=cnt;
            }
            else{
                scanf("%s",ss);
                int l=strlen(ss);
                int i=0;
                int ans=0,cnt=0;
                str1="";
                for(int i=0;i<l;i++)
                {
                    if(ss[i]=='&') ans--;
                    else if(ss[i]=='*') ans++;
                    else str1+=ss[i];
                }
                cnt=mp[str1];
                if(cnt>0) cnt+=ans;
                else cnt=0;
                if(cnt<=0) puts("errtype");
                else
                {
                    printf("void");
                    for(int i=1;i<cnt;i++)
                    printf("*");
                    puts("");
                }
            }
        }
    }
    return 0;
}
/*
5
typedef void* ptv
typeof ptv
typedef &&ptv node
typeof node
typeof &ptv
17
typedef void* b
typedef b* c
typeof b
typeof c
typedef &b b
typeof b
typeof c
typedef &&b* c
typeof c
typedef &b* c
typeof c
typedef &void b
typeof b
typedef b******* c
typeof c
typedef &&b* c
typeof c
3
typedef void** voidd
typeof voidd
typeof void
12
typedef void a
typedef a* b
typedef b* c
typeof a
typeof b
typeof c
typedef &c a
typedef &a b
typedef &b c
typeof a
typeof b
typeof c
*/