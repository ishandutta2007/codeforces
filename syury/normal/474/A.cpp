#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

char shift;
string s;
string s1;

char shiftChar(char sh,char arg){
  if (sh=='L'){
    switch(arg){
      case 'q' : return 'w';
      case 'w' : return 'e';
      case 'e' : return 'r';
      case 'r' : return 't';
      case 't' : return 'y';
      case 'y' : return 'u';
      case 'u' : return 'i';
      case 'i' : return 'o';
      case 'o' : return 'p';
      case 'a' : return 's';
      case 's' : return 'd';
      case 'd' : return 'f';
      case 'f' : return 'g';
      case 'g' : return 'h';
      case 'h' : return 'j';
      case 'j' : return 'k';
      case 'k' : return 'l';
      case 'l' : return ';';
      case 'z' : return 'x';
      case 'x' : return 'c';
      case 'c' : return 'v';
      case 'v' : return 'b';
      case 'b' : return 'n';
      case 'n' : return 'm';
      case 'm' : return ',';
      case ',' : return '.';
      case '.' : return '/';
      default : break;
    }
  }
    else{
      switch(arg){
      case 'p' : return 'o';
      case 'w' : return 'q';
      case 'e' : return 'w';
      case 'r' : return 'e';
      case 't' : return 'r';
      case 'y' : return 't';
      case 'u' : return 'y';
      case 'i' : return 'u';
      case 'o' : return 'i';
      case ';' : return 'l';
      case 's' : return 'a';
      case 'd' : return 's';
      case 'f' : return 'd';
      case 'g' : return 'f';
      case 'h' : return 'g';
      case 'j' : return 'h';
      case 'k' : return 'j';
      case 'l' : return 'k';
      case '/' : return '.';
      case 'x' : return 'z';
      case 'c' : return 'x';
      case 'v' : return 'c';
      case 'b' : return 'v';
      case 'n' : return 'b';
      case 'm' : return 'n';
      case ',' : return 'm';
      case '.' : return ',';
      default : break;
    }
  }
}

string shiftString(char sh,string str){
  string res = "";
  for (int i=0;i<str.length();i++){
  res.push_back(shiftChar(sh,str[i]));
  }
  return res;
}

int main(){
  getline(cin,s1);
  getline(cin,s);
  shift = s1[0];
  s1 = shiftString(shift,s);
  printf("%s",s1.c_str());
  return 0;
}