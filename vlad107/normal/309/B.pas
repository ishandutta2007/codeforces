{$r-,q-,s-,i-,o+}
var
  lz,cr,x,nom,ans,n,r,c,i,j,k:longint;
  s:array[0..1000010]of ansistring;
  l:array[0..1000010]of int64;
  ch:char;
  z:ansistring;
  prev:array[0..1001000,0..21]of longint;

begin
  readln(n,r,c);
  l[0]:=0;
  for i:=1 to n do begin
    read(ch);
    while not(ch in ['a'..'z'])do read(ch);
    s[i]:='';
    while (ch in ['a'..'z'])do begin
      s[i]:=s[i]+ch;
      read(ch);
    end;
    l[i]:=length(s[i])+l[i-1];
  end;
  j:=1;
  for i:=1 to n do begin
    while (l[i]-l[j-1]+i-j>c)do inc(j);
    if (j>i)then prev[i][0]:=-1 else prev[i][0]:=j-1;
    for k:=1 to 20 do 
      if (prev[i][k-1]=-1)then prev[i][k]:=-1 else prev[i][k]:=prev[prev[i][k-1]][k-1];
  end;
  ans:=0;
  for i:=1 to n do begin
    cr:=r;
    x:=i;
    for j:=20 downto 0 do begin
      if (prev[x][j]=-1)then continue;
      if (1 shl j>cr)then continue;
      dec(cr,1 shl j);
      x:=prev[x][j];
    end;
    if (i-x>ans)then begin
      nom:=i;
      ans:=i-x;
    end;
  end;
  z:='';
  lz:=0;
  for i:=nom-ans+1 to nom do begin
    if (lz+length(s[i])+ord(lz<>0)>c)then begin
      writeln(z);
      z:='';
      lz:=0;
    end;
    if (lz<>0)then z:=z+' ';
    z:=z+s[i];
    lz:=lz+length(s[i])+ord(lz<>0);
  end;
  if (z<>'')then writeln(z);
end.