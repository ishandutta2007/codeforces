var
  l,l1,l2,nj,res,i,j:longint;
  s,s1,s2:ansistring;
  f:array[0..31111,'a'..'z']of longint;

begin
  readln(s1);
  readln(s2);
  l1:=length(s1);
  l2:=length(s2);
  s:=s1+s1;
  l:=length(s);
  fillchar(f,sizeof(f),$FF);
  for i:=l-1 downto 0 do begin
    f[i]:=f[i+1];
    f[i][s[i+1]]:=i+1;
  end;
  j:=0;
  res:=1;
  for i:=1 to l2 do begin
    nj:=f[j][s2[i]];
    if (nj>l1)then begin
      dec(nj,l1);
      inc(res);
    end else
    if (nj=j)then inc(res) else
    if (nj<0)then begin
      writeln(-1);
      exit;
    end;
    j:=nj;
  end;
  writeln(res);
end.