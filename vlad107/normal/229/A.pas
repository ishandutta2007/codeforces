const
  inf=1000000000;

var
  first,last,ans,cr,k,n,m,i,j:longint;
  found:boolean;
  ch:char;
  f,a:array[0..111,0..11111]of longint;
  
  function min(x,y:longint):longint;
    begin
      if (x<y)then min:=x else min:=y;
    end;

begin
  readln(n,m);
  for i:=1 to n do begin
    found:=false;
    for j:=1 to m do begin
      read(ch);
      a[i][j]:=ord(ch)-48;
      if (a[i][j]=1)then found:=true;
    end;
    readln;
    if (not found)then begin
      writeln(-1);
      exit;
    end;
    last:=m;
    while (a[i][last]=0)do dec(last);
    for j:=1 to m do begin
      if (a[i][j]=1)then last:=j;
      f[i][j]:=min(abs(last-j),abs(last-j+m));
      f[i][j]:=min(f[i][j],abs(last-j-m));
    end;
    first:=1;
    while (a[i][first]=0)do inc(first);
    for j:=m downto 1 do begin
      if (a[i][j]=1)then first:=j;
      f[i][j]:=min(f[i][j],abs(first-j));
      f[i][j]:=min(f[i][j],abs(first-j+m));
      f[i][j]:=min(f[i][j],abs(first-j-m));
    end;
  end;
  ans:=inf;
  for j:=1 to m do begin
    cr:=0;
    for i:=1 to n do 
      inc(cr,f[i][j]);
    if (cr<ans)then ans:=cr;
  end;
  writeln(ans);
end.