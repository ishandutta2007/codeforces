var
  n,ls,lp,i,lcm,ka,kb:longint;
  f:array[0..1000500]of longint;
  s,p:ansistring;

  function gcd(a,b:longint):longint; 
    begin
      while (a<>0)and(b<>0)do
        if (a>b)then a:=a mod b else b:=b mod a;
      gcd:=a+b;
    end;
    
  function win(a,b:char):boolean;
    begin
      win:=(a+b='RS')or
           (a+b='SP')or
           (a+b='PR');
    end;

begin
  readln(n);
  readln(s);
  readln(p);
  ls:=length(s);
  lp:=length(p);
  lcm:=ls*lp div gcd(ls,lp);
  for i:=ls+1 to lcm do s:=s+s[(i-1)mod ls+1];
  for i:=lp+1 to lcm do p:=p+p[(i-1)mod lp+1];
  ka:=0;kb:=0;
  for i:=1 to lcm do 
    if (s[i]=p[i])then f[i]:=0 else 
    if (win(s[i],p[i]))then f[i]:=1 else
    f[i]:=-1;
  for i:=1 to lcm do 
    if (f[i]<0)then inc(ka)else
    if (f[i]>0)then inc(kb);
  ka:=ka*(n div lcm);
  kb:=kb*(n div lcm);
  for i:=1 to n mod lcm do 
    if (f[i]<0)then inc(ka)else
    if (f[i]>0)then inc(kb);
  writeln(ka,' ',kb);
end.