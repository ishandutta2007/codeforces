var s,w:string;
ans,n,m,i,j,k,p,t:integer;
a,b:array [1..26] of integer;

begin
readln(s);
readln(m);
n:=length(s);
for i:=1 to 26 do a[i]:=0;
for i:=1 to n do
  begin
  a[ord(s[i])-96]+=1;
  end;
k:=0;
for i:=1 to 26 do
  begin
  if a[i]>0 then k+=1;
  end;
if k>m then writeln(-1) else
  begin
  for ans:=1 to n do
    begin
    t:=0;
    for i:=1 to 26 do
      begin
      if a[i] mod ans=0 then b[i]:=a[i] div ans else b[i]:=a[i] div ans+1;
      t+=b[i];
      end;
    if t<=m then
      begin
      writeln(ans);
      for i:=1 to 26 do
        begin
        for j:=1 to b[i] do write(chr(96+i));
        end;
      for i:=t+1 to m do write('a');
      halt;
      end;
    end;
  end;
end.