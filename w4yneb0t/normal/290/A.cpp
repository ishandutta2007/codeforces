#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
char wt[50][200]={"Washington, George ",
"Adams, John ",
"Jefferson, Thomas ",
"Madison, James ",
"Monroe, James ",
"Adams, John Quincy ",
"Jackson, Andrew ",
"Van Buren, Martin ",
"Harrison, William Henry ",
"Tyler, John ",
"Polk, James Knox ",
"Taylor, Zachary ",
"Fillmore, Millard ",
"Pierce, Franklin ",
"Buchanan, James ",
"Lincoln, Abraham ",
"Johnson, Andrew ",
"Grant, Ulysses S. ",
"Hayes, Rutherford Birchard ",
"Garfield, James Abram ",
"Arthur, Chester Alan ",
"Cleveland, Grover ",
"Harrison, Benjamin ",
"Cleveland, Grover ",
"McKinley, William ",
"Roosevelt, Theodore ",
"Taft, William Howard ",
"Wilson, Woodrow ",
"Harding, Warren Gamaliel ",
"Coolidge, Calvin ",
"Hoover, Herbert Clark ",
"Roosevelt, Franklin Delano ",
"Truman, Harry ",
"Eisenhower, Dwight David ",
"Kennedy, John Fitzgerald ",
"Johnson, Lyndon Baines ",
"Nixon, Richard Milhous ",
"Ford, Gerald Rudolph ",
"Carter, James Earl Jr. ",
"Reagan, Ronald Wilson ",
"Bush, George Herbert Walker ",
"Clinton, William Jefferson ",
"Bush, George Walker ",
"Obama, Barack Hussein "};
int main(){
  int a;
  cin>>a;
  a--;
  for(int i=0;wt[a][i]!=',';i++){
    cout<<wt[a][i];
  }
  cout<<endl;
  return 0;
}