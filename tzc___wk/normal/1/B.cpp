#include <iostream>
using namespace std;
string toStr(int x)
{
	string s="";
	if (x==0) return "0";
	while(x>0)
	{
		s=(char)('0'+(x%10))+s;
		x/=10;
	}
	return s;
}
int toNum(string s)
{
	int x=0;
	for(int i=0;i<(int)s.length();i++)
		x=10*x+(int)(s[i]-'0');
	return x;
}
int getId(string s)
{
	int res=1;
	int z=1;
	for (int i=(int)s.length()-1;i>=0;i--)
	{
		res+=(int)(s[i]-'A')*z;
		z*=26;
		if (i!=0)
			res+=z;
	}
	return res;
}
string getStr(int id)
{
	id--;
	int len=1;
	int z=26;
	while(id>=z)
	{
		id-=z;
		z*=26;
		len++;
	}
	string s="";
	for (int i=0;i<len;i++)
		s.push_back('A');
	for(int i=0;i<len;i++)
	{
		z/=26;
		while(id>=z)
		{
			id-=z;
			s[i]++;
		}
	}
	return s;
}
bool checkType(string s)
{
	int id=0;
	while('A'<=s[id]&&s[id]<='Z') id++;
	for(int i=id;i<(int)s.length();i++)
		if ('A'<=s[i]&&s[i]<='Z')
			return false;
	return true;
}
string solve1(string s)
{
	int id=0;
	while('A'<=s[id]&&s[id]<='Z') id++;
	return "R"+s.substr(id,s.length()-id)+"C"+toStr(getId(s.substr(0,id)));
}
string solve2(string s)
{
	int id=1;
	while('0'<=s[id]&&s[id]<='9') id++;
	return getStr(toNum(s.substr(id+1,s.length()-id-1)))+s.substr(1,id-1);
}
string solve()
{
	string s;
	cin >> s;
	if (checkType(s))
		return solve1(s);
	else
		return solve2(s);
}
void process()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cout<<solve()<<"\n";
}
int main()
{
	process(); 
	return 0;
}