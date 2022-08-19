{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,i,j,tmp: longint;
  ok: boolean;
  len,num,pz: array [0..1010] of longint;
  a: array [0..1010,0..1010] of char;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do
  begin
    read(len[i]);
    num[i]:=i;
  end;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if len[i] > len[j] then
      begin
        tmp:=len[i]; len[i]:=len[j]; len[j]:=tmp;
        tmp:=num[i]; num[i]:=num[j]; num[j]:=tmp;
      end;
  len[0]:=0;
  for i:=1 to n do
  begin
    if i > 1 then
    begin
      for j:=1 to len[i-1] do a[i,j]:=a[i-1,j];
      ok:=False;
      for j:=len[i-1] downto 1 do
        if a[i,j] = '0' then
        begin
          a[i,j]:='1';
          ok:=True;
          break;
        end
        else a[i,j]:='0';
      if not ok then
      begin
        writeln('NO');
        halt;
      end;
    end;
    for j:=len[i-1]+1 to len[i] do a[i,j]:='0';
  end;
  for i:=1 to n do pz[num[i]]:=i;
  writeln('YES');
  for i:=1 to n do
  begin
    for j:=1 to len[pz[i]] do write(a[pz[i],j]);
    writeln;
  end;
  close(input);
  close(output);
end.