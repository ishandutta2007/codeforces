{$r-,q-,s-,i-,o+}
var
  s:ansistring;
  l,r,tt,ls,i,j:longint;
  fs,ff:array[0..5001,0..5001]of longint;

begin
  readln(s);
  ls:=length(s);
  for i:=1 to ls do begin
    fs[i][i]:=1;
    ff[i][i]:=1;
    j:=0;
    while (i-j-1>0)and(i+j+1<=ls)and(s[i-j-1]=s[i+j+1])do begin
      inc(fs[i-j-1][i+j+1]);
      inc(ff[i-j-1][i+j+1]);
      inc(j);
    end;
    j:=0;
    while (i-j>0)and(i+j+1<=ls)and(s[i-j]=s[i+j+1])do begin
      inc(fs[i-j][i+j+1]);
      inc(ff[i-j][i+j+1]);
      inc(j);
    end;
  end;
  for i:=1 to ls do begin
    fs[i][i-1]:=0;
    for j:=i to ls do fs[i][j]:=fs[i][j-1]+fs[i][j];
    ff[i+1][i]:=0;
    for j:=i downto 1 do ff[j][i]:=ff[j+1][i]+ff[j][i];
  end;
  for i:=ls downto 1 do
    for j:=i to ls do
      fs[i][j]:=fs[i][j]+ff[i+1][j]+fs[i+1][j-1];
  readln(tt);
  while (tt>0)do begin
    dec(tt);
    read(l,r);
    writeln(fs[l][r]);
  end;
end.