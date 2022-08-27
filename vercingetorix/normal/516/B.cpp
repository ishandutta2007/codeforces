#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair
ll mod=1000000007;

bool field[2000][2000];
bool used[2000][2000];
char ans[2000][2000];
int nb[2000][2000];

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif

//int ans=0;
int n,m;
scanf("%d %d\n", &n, &m);
string s;
char c;
int num=0;
for(int i=0; i<n; i++) {
    s.clear();
    for(int j=0; j<m; j++) {
        scanf("%c", &c);
        used[i][j]=false;
        nb[i][j]=0;
        ans[i][j]='*';
        if(c=='.') {
            field[i][j] = true;
            num++;
        }
        else field[i][j] = false;
    }
    scanf("\n");
}

for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
        if(!field[i][j]) continue;
        if ((i>0)) nb[i-1][j]++;
        if ((j>0)) nb[i][j-1]++;
        if ((i<n-1)) nb[i+1][j]++;
        if ((j<m-1)) nb[i][j+1]++;
    }
}
std::deque<pair<int, int>> solo;
for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
        if((field[i][j])&&(nb[i][j]==1)) solo.pb(mp(i,j));
    }
}
while (solo.size()>0) {
    /*for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
        printf("%c", ans[i][j]);
    }
    printf("\n");
}
    printf("\n");*/
    pair<int,int> cur = solo.back();
    int y=cur.second;
    int x=cur.first;

    solo.pop_back();
    if(!field[x][y]) continue;
    field[x][y]=false;
    num--;
    used[x][y]=true;
    bool f=false;
    for(int i=0; i<4; i++) {
         int xx = (i<2)? 0 : (i<3) ? -1 : 1;
         int yy = (i>=2)? 0 : (i<1) ? -1 : 1;
         xx+=x;
         yy+=y;
        {
            if((xx>=0)&&(xx<n)&&(yy>=0)&&(yy<m)&&(field[xx][yy])) {
                f=true;
                field[xx][yy]=false;
                if(xx-x==1) {
                                ans[x][y]='^';
                                ans[xx][y]='v';
                            }
                            if(xx-x==-1) {
                                ans[xx][y]='^';
                                ans[x][y]='v';
                            }
                            if(yy-y==1) {
                                ans[x][y]='<';
                                ans[x][yy]='>';
                            }
                            if(y-yy==1) {
                                ans[x][yy]='<';
                                ans[x][y]='>';
                            }
                num--;
                for(int j=0; j<4; j++) {
                     int xxx = (j<2)? 0 : (j<3) ? -1 : 1;
                    int yyy = (j>=2)? 0 : (j<1) ? -1 : 1;
                       xxx+=xx;
                        yyy+=yy;
                    {
                        if((xxx>=0)&&(xxx<n)&&(yyy>=0)&&(yyy<m)){
                            nb[xxx][yyy]--;
                            if(field[xxx][yyy] && (nb[xxx][yyy]==1)) solo.pb(mp(xxx,yyy));
                            
                        }
                    }
                }
            }
        }
    }
    if(!f) {
        cout<<"Not unique";
        return 0;
    }
}
if(num!=0){
    cout<<"Not unique";
        return 0;
   
}
for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
        printf("%c", ans[i][j]);
    }
    printf("\n");
}



return 0;


}