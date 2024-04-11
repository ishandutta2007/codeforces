var
  ans,n,i,j,c1,c2,ch,ls:longint;
  f:array[0..27,0..27]of longint;
  s:ansistring;

begin
  readln(n);
  for c1:=1 to 26 do 
    for c2:=1 to 26 do 
      if (c1=c2)then f[c1][c2]:=0 else f[c1][c2]:=-1;
  for i:=1 to n do begin
    readln(s);
    ls:=length(s);
    c1:=ord(s[1])-96;
    c2:=ord(s[ls])-96;
    for ch:=1 to 26 do begin
      if (f[ch][c1]=-1)then continue;
      if (f[ch][c1]+ls>f[ch][c2])then f[ch][c2]:=f[ch][c1]+ls;
    end;
  end;
  ans:=0;
  for ch:=1 to 26 do if (f[ch][ch]>ans)then ans:=f[ch][ch];
  writeln(ans);
end.