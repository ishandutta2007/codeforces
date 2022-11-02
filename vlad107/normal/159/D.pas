{$r-,q-,s-,i-,o+}
const
  MAXN=2222;
 
var
  n,i,j:longint;
  res,suma,sumb:int64;
  s:ansistring;
  f:array[0..MAXN,0..MAXN]of boolean;
  a,b:array[0..MAXN]of longint;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  readln(s);
  n:=length(s);
  fillchar(a,sizeof(a),$0);
  fillchar(b,sizeof(b),$0);
  fillchar(f,sizeof(f),false);
  for i:=1 to n do f[i][i]:=true;
  for i:=1 to n-1 do 
    if (s[i]=s[i+1])then f[i][i+1]:=true;
  for i:=n downto 1 do 
    for j:=i+2 to n do 
      f[i][j]:=f[i+1][j-1]and (s[i]=s[j]);
  for i:=1 to n do 
    for j:=i to n do 
      if (f[i][j])then begin
        inc(a[j]);
        inc(b[i]);
      end;
  sumb:=0;
  for i:=1 to n do sumb:=sumb+b[i];
  res:=0;
  for i:=1 to n do begin
    sumb:=sumb-b[i];
    res:=res+int64(a[i])*sumb;
  end;
  writeln(res);
  close(output);close(input);
end.