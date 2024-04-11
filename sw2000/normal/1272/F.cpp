#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
string s1,s2;
int dp[210][210][210],len1,len2;

struct Node
{
    int i,j,k;
};

Node last[210][210][210];

int main()
{
    //freopen("in.txt","r",stdin);
    cin>>s1>>s2;
    len1=s1.size(),len2=s2.size();
    s1+="#",s2+="#";

    queue<Node>q;
    q.push((Node){0,0,0});
    while(!q.empty())
    {
        Node x=q.front();q.pop();
        Node y={x.i+(s1[x.i]=='('),x.j+(s2[x.j]=='('),x.k+1};
        if(y.k>=0&&y.k<210&&!dp[y.i][y.j][y.k])
        {
            dp[y.i][y.j][y.k]=dp[x.i][x.j][x.k]+1;
            q.push(y);
            last[y.i][y.j][y.k]=x;
        }
        y=(Node){x.i+(s1[x.i]==')'),x.j+(s2[x.j]==')'),x.k-1};
        if(y.k>=0&&y.k<210&&!dp[y.i][y.j][y.k])
        {
            dp[y.i][y.j][y.k]=dp[x.i][x.j][x.k]+1;
            q.push(y);
            last[y.i][y.j][y.k]=x;
        }
    }

    vector<Node>ans;
    Node st={len1,len2,0};
    while(1)
    {
        ans.push_back(st);
        if(!st.i&&!st.j&&!st.k)break;
        st=last[st.i][st.j][st.k];
    }

    for(int i=ans.size()-1;i;i--)
    {
        Node x=ans[i],y=ans[i-1];
        if(x.k>y.k)printf(")");
        else printf("(");
    }

    return 0;
}