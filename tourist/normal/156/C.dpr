{$R-,S-,Q-,I-,O+}
const md = round(1e9+7);
var
  f: array [0..111,0..3333] of longint;
  s: ansistring;
  tt,qq,n,i,j,k,c: longint;
begin
  fillchar(f,sizeof(f),0);
  f[0,0]:=1;
  for i:=0 to 100 do
    for j:=0 to 3000 do
      if f[i,j] > 0 then
        for k:=0 to 25 do
        begin
          inc(f[i+1,j+k],f[i,j]);
          if f[i+1,j+k] >= md then dec(f[i+1,j+k],md);
        end;
  readln(tt);
  for qq:=1 to tt do
  begin
    readln(s);
    n:=length(s); c:=0;
    for i:=1 to n do c:=c+Ord(s[i])-97;
    writeln((f[n,c]+md-1) mod md);
  end;
end.