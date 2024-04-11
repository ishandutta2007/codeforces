#include <stdio.h>
#include <vector>
using namespace std;
struct Node
{
 vector<int> edges;
} Tree[100050];
double dfs(int cur, int prev, double path)
{
 int i,j=0;
 double mass=0;
 for(i=0;i<Tree[cur].edges.size();i++)
 {
  int v=Tree[cur].edges[i];
  if(v!=prev)
  {
   j++;
   mass+=dfs(v,cur,path+1);
  }
 }
 if(j==0) return path;
 else return mass/j;
}
int main()
{
 int n,u,v,i;
 scanf("%i",&n);
 for(i=0;i<n-1;i++)
 {
  scanf("%i%i",&u,&v);
  Tree[u].edges.push_back(v);
  Tree[v].edges.push_back(u);
 }
 printf("%.12llf",dfs(1,0,0));
 return 0;
}