
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)

char a[2005][2005];
struct node
{
    int mx,Mx,my,My;
}p[30];
struct snake
{
    bool inx,iny;
    int v,minn,maxx;
}s[30];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=1;i<=26;++i) p[i].mx=1e9,p[i].Mx=-1,p[i].my=1e9,p[i].My=-1;
        memset(s,0,sizeof(s));
        char maxc = 0;
        int n,m;
        cin>>n>>m;
        int xx=-1,yy=-1;
        forii forjj
        {
            cin>>a[i][j];
            if(a[i][j]=='.') continue;
            if(a[i][j] > maxc)
            {
                maxc = a[i][j];
                xx=i,yy=j;
            }
            int tmp = a[i][j]-'a'+1;
            maxc = max(a[i][j], maxc);
            p[tmp].mx = min(p[tmp].mx, i),
            p[tmp].Mx = max(p[tmp].Mx, i),
            p[tmp].my = min(p[tmp].my, j),
            p[tmp].My = max(p[tmp].My, j);
        }
        if(!maxc) {cout<<"YES\n0\n";continue;}
        int k = maxc - 'a' + 1, ok = 1;
        for(int i=1;i<=k;++i)
        {
            if(p[i].Mx<0) continue;
            //cout<<i<<" "<<p[i].mx<<" "<<p[i].Mx<<" "<<p[i].my<<" "<<p[i].My<<endl;
            if(p[i].mx == p[i].Mx)
            {
                s[i].inx = 1,
                s[i].v = p[i].mx,
                s[i].minn = p[i].my,
                s[i].maxx = p[i].My;
            }
            else if(p[i].my == p[i].My)
            {
                s[i].iny = 1,
                s[i].v = p[i].my,
                s[i].minn = p[i].mx,
                s[i].maxx = p[i].Mx;
            }
            else
            {
                ok = 0;
                break;
            }
        }
        if(!ok) {cout<<"NO"<<endl;continue;}
        //for(int i=1;i<=k;++i) cout<<s[i].inx<<" "<<s[i].v<<" "<<s[i].minn<<" "<<s[i].maxx<<endl;
        forii
        {
            forjj
            {
                if(a[i][j]=='.')
                {
                    for(int l=1;l<=k;++l)
                    {
                        if(s[l].inx)
                        {
                            if(i==s[l].v && j>=s[l].minn && j<=s[l].maxx) {ok=0;break;}
                        }
                        else if(s[l].iny)
                        {
                            if(j==s[l].v && i>=s[l].minn && i<=s[l].maxx) {ok=0;break;}
                        }
                    }
                    if(!ok) break;
                    continue;
                }
                int tmp = a[i][j] - 'a' + 1;
                for(int l=tmp+1;l<=k;++l)
                {
                    
                    if(s[l].inx)
                    {
                        if(i==s[l].v && j>=s[l].minn && j<=s[l].maxx) {ok=0;break;}
                    }
                    else if(s[l].iny)
                    {
                        if(j==s[l].v && i>=s[l].minn && i<=s[l].maxx) {ok=0;break;}
                    }
                }
                if(s[tmp].inx)
                {
                    if(i!=s[tmp].v || j>s[tmp].maxx || j<s[tmp].minn)
                    {
                        ok=0;
                        break;
                    }
                }
                else if(s[tmp].iny)
                {
                    if(j!=s[tmp].v || i>s[tmp].maxx || i<s[tmp].minn)
                    {
                        ok=0;
                        break;
                    }
                }
                if(!ok) break;
            }
            if(!ok) break;
        }
        if(!ok) {cout<<"NO"<<endl;continue;}
        cout<<"YES"<<endl;
        cout<<k<<endl;
        for(int i=1;i<=k;++i)
        {
            if(s[i].inx) cout<<s[i].v<<" "<<s[i].minn<<" "<<s[i].v<<" "<<s[i].maxx<<endl;
            else if(s[i].iny) cout<<s[i].minn<<" "<<s[i].v<<" "<<s[i].maxx<<" "<<s[i].v<<endl;
            else cout<<xx<<" "<<yy<<" "<<xx<<" "<<yy<<endl;
        }
    }
}