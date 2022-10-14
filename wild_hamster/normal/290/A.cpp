#include <iostream>
#include <cstring>
using namespace std;
int main()
{
int n,rez,i,j,k;
string c[40]={"Washington","Adams","Jefferson","Madison","Monroe",
"Adams","Jackson","Van Buren","Harrison","Tyler","Polk",
"Taylor","Fillmore","Pierce","Buchanan","Lincoln","Johnson","Grant","Hayes",
"Garfield","Arthur","Cleveland","Harrison","Cleveland","McKinley",
"Roosevelt","Taft","Wilson","Harding","Coolidge","Hoover","Roosevelt",
"Truman","Eisenhower","Kennedy","Johnson","Nixon","Ford","Carter","Reagan"};
cin>>n;
cout<<c[n-1]<<endl;
return 0;
}