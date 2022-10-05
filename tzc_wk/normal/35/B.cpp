#include <bits/stdc++.h>
using namespace std;
const int maxn=35;
bool mark[maxn][maxn];
map<string, pair<int, int> > M;
int n,m,k;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>n>>m>>k;
    for(int e=0;e<k;e++){
        string type;
        cin>>type;
        if(type[0]=='+')
        {
            string name;
            int x,y;
            cin>>x>>y>>name;
            bool is=false;
            for (int i=x;i<=n;i++)
            {
            	if(is)	break;
                int j;
                if (i==x) j=y;
                else j=1;
                for(;j<=m;j++) if(!mark[i][j])
                {
                    mark[i][j]=true;
                    M[name]=make_pair(i,j);
                    is=true;
                    break;
                }
            }
        }
        else
        {
            string name;
            cin>>name;
            if (M[name].first == 0) {cout<<"-1 -1"<<endl;continue;}
            else cout<<M[name].first<<" "<<M[name].second<<endl;
            mark[M[name].first][M[name].second]=false;
            M[name].first = 0; M[name].second=0;
        }
    }
	return 0;
}