var i,j,n,k,ans,t:integer;
a,g,d,b,c:array [0..5050] of integer;
s:string;


begin
g[0]:=0;
g[1]:=1;
g[2]:=1;
for i:=3 to 5010 do
  begin
  for j:=0 to i+5 do d[j]:=0;
  d[g[i-2]]:=1;
  for j:=2 to (i-1) do d[g[j-2] xor g[i-j-1]]:=1;
  for j:=0 to i+1 do
    begin
    if d[j]=0 then
      begin
      g[i]:=j;
      break;
      end;
    end;
  end;
readln(s);
n:=length(s);
a[1]:=0;
a[n]:=0;
for i:=2 to n-1 do
  begin
  if s[i-1]=s[i+1] then a[i]:=1 else a[i]:=0;
  end;
k:=0;
t:=0;
for i:=1 to n do
  begin
  if a[i]=1 then
    begin
    if t=0 then
      begin
      k+=1;
      t:=i;
      end;
    end else
    begin
    if t>0 then
      begin
      b[k]:=i-t;
      t:=0;
      end;
    end;
  end;
ans:=0;
for i:=1 to k do ans:=ans xor g[b[i]];
if ans=0 then writeln('Second') else
  begin
  writeln('First');
  for i:=1 to n do c[i]:=a[i];
  for j:=1 to n do
    begin
    if a[j]=1 then
      begin
      a[j]:=0;
      a[j-1]:=0;
      a[j+1]:=0;
      k:=0;
      t:=0;
      for i:=1 to n do
        begin
        if a[i]=1 then
          begin
          if t=0 then
            begin
            k+=1;
            t:=i;
            end;
          end else
          begin
          if t>0 then
            begin
            b[k]:=i-t;
            t:=0;
            end;
          end;
        end;
      ans:=0;
      for i:=1 to k do ans:=ans xor g[b[i]];
      if ans=0 then
        begin
        writeln(j);
        break;
        end else
        begin
        a[j]:=c[j];
        a[j-1]:=c[j-1];
        a[j+1]:=c[j+1];
        end;
      end;
    end;
  end;
end.