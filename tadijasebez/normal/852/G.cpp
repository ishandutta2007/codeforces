#include <stdio.h>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int M=5000000;
int Trie[M][5],clock,root;
int x[M];
string word;
void Set(int &c, int pos)
{
if(!c) c=++clock;
if(pos==word.size()){ x[c]++;return;}
Set(Trie[c][word[pos]-'a'],pos+1);
}
bool vis[M];
vector<int> back;
int sol;
void Get(int c, int pos)
{
int i;
if(pos==word.size()){ if(!vis[c]) sol+=x[c],vis[c]=1,back.push_back(c);return;}
if(word[pos]=='?')
{
for(i=0;i<5;i++)
{
Get(Trie[c][i],pos+1);
}
Get(c,pos+1);
return;
}
Get(Trie[c][word[pos]-'a'],pos+1);
}
int main()
{
int n,m,i;
scanf("%i %i",&n,&m);
while(n--)
{
cin >> word;
Set(root,0);
}
while(m--)
{
cin >> word;
sol=0;
for(i=0;i<back.size();i++) vis[back[i]]=0;
back.clear();
Get(root,0);
printf("%i\n",sol);
}
return 0;
}