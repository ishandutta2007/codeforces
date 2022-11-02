{$r-,q-,s-,i-,o+}
var
  rs,s:ansistring;
  qt,n,i,j,m1,m2,n2:longint;
  n1,ch:char;
  kc:array['a'..'z']of longint;
  kt,nom,kg:array[0..1111]of longint;
  g:array[0..1111,0..1111]of longint;
  was:array[0..1111]of boolean;
  function gcd(x,y:longint):longint;
    begin
      while (x<>0)and(y<>0)do
        if (x>y)then x:=x mod y else y:=y mod x;
      gcd:=x+y;
    end;
  procedure dfs(x:longint);
    var
      i:longint;
    begin
      if (was[x])then exit;
      was[x]:=true;
      inc(kt[qt]);
      nom[x]:=qt;
      for i:=1 to kg[x] do dfs(g[x][i]);
    end;
begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  readln(s);
  n:=length(s);
  fillchar(kc,sizeof(kc),$0);
  for i:=1 to n do inc(kc[s[i]]);
  rs:='';
  for i:=1 to n do rs:=rs+' ';

  for i:=1 to n do
    for j:=1 to n do
      if (i<>j)and(gcd(i,j)<>1)then begin
        inc(kg[i]);g[i][kg[i]]:=j;
        inc(kg[j]);g[j][kg[j]]:=i;
      end;
  fillchar(nom,sizeof(nom),$0);
  for i:=1 to n do
    if (nom[i]=0)then begin
      inc(qt);
      kt[qt]:=0;
      dfs(i);
    end;
  for i:=1 to qt do begin
    m1:=0;
    for ch:='a' to 'z' do
      if (kc[ch]>m1)then begin
        m1:=kc[ch];
        n1:=ch;
      end;
    m2:=0;n2:=0;
    for j:=1 to qt do
      if (kt[j]>m2)then begin
        m2:=kt[j];
        n2:=j;
      end;
    if (m2>m1)then begin
      writeln('NO');
      exit;
    end;
    dec(kc[n1],m2);
    kt[n2]:=0;
    for j:=1 to n do
      if (nom[j]=n2)then rs[j]:=n1;
  end;
  writeln('YES');
  writeln(rs);
  close(output);close(input);
end.