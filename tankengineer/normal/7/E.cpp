//7E WJMZBMR 
/*

4Expr Muti Adde Susp

level0level0level1Mraco
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<iostream>
#include<cctype>

using namespace std;

enum Token {
  //4 Expr Muti Adde Susp
  Expr, Muti, Adde, Susp
};

map<string, Token> def;

string input;
int at;

char peek_char() { //
  while (input[at] == ' ') at++;
  return input[at];
}

char next_char() { // 
  char ch = peek_char();
  at++;
  return ch;
}

inline Token invoke(char op, Token l, Token r) { // l op r  
  if (l == Susp || r == Susp) return Susp; 
  if (op == '+' || op == '-') {
    if (op == '-' && r == Adde) return Susp;
    return Adde;
  }
  if (op == '*' || op == '/') {
    if (l == Adde || r == Adde) return Susp;
    if (op == '/' && r == Muti) return Susp;
    return Muti; 
  }
  return Susp;
}

Token expr();
Token adde();
Token muti();

Token expr() { //+- 
  Token ret = adde();
  while (1) {
    char op = peek_char();
    if (op == '+' || op == '-') {
      next_char();
      ret = invoke(op, ret, adde());
    } else {
      break;
    }
  }
  return ret;
}

Token adde() { //*/ 
  Token ret = muti();
  while (1) {
    char op = peek_char();
    if (op == '*' || op == '/') {
      next_char();
      ret = invoke(op, ret, muti());
    } else {
      break;
    }
  } 
  return ret;
}

Token muti() { //Mraco 
  if (peek_char() == '(') {
    next_char();
    Token ret = expr();
    next_char();
    return ret == Susp ? Susp : Expr;
  } else { //Mraco 
    string id;
    while (isalnum(peek_char())) id += next_char();
    if (def.count(id)) {
      return def[id];
    } else {
      return Expr;
    }
  }
}

Token parse() {
  getline(cin, input);
  at = 0;
  input += "@";
  return expr();
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf(" ");
    scanf("# define");
    string name;
    cin >> name;
    def[name] = parse();
  }
  scanf(" ");
  cout << (parse() == Susp ? "Suspicious" : "OK") << endl;
  return 0;
}