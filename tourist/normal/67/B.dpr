{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  a,b: array [0..1010] of longint;
  p,n,k,m,i,j,u: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,k);
  for i:=1 to n do read(a[i]);
  m:=1; b[1]:=n;
  for i:=n-1 downto 1 do
  begin
    u:=0;
    for j:=1 to m+1 do
    begin
      if u = a[i] then
      begin
        for p:=m+1 downto j+1 do b[p]:=b[p-1];
        b[j]:=i;
        inc(m);
        break;
      end;
      if b[j] >= i+k then inc(u);
    end;
  end;
  for i:=1 to n-1 do write(b[i],' ');
  writeln(b[n]);
  close(input);
  close(output);
end.