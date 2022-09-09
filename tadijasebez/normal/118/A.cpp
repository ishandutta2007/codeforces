#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;
char word[100000];
vector<char> sol;
int main()
{
int n,i;
scanf("%s",&word);
n=(unsigned) strlen(word);
for(i=0;i<n;i++)
{
if(word[i]<'a')
word[i]=word[i]+'a'-'A';
if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u' || word[i]=='y') n=n;
else
{
sol.push_back('.');
sol.push_back(word[i]);
}
}
for(i=0;i<sol.size();i++) printf("%c",sol[i]);
return 0;
}