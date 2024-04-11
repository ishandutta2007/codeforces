{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,m,k,i,j,v,min,km: longint;
  d,t,mk: array [0..10010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m,k);
  for i:=1 to m do
  begin
    read(d[i]);
    t[i]:=0;
  end;
  for i:=1 to k do
  begin
    read(v);
    for j:=1 to m do
      if v mod d[j] = 0 then inc(t[j]);
  end;
  min:=maxlongint; km:=0;
  for i:=1 to m do
  begin
    if t[i] < min then
    begin
      min:=t[i];
      km:=0;
    end;
    if t[i] = min then
    begin
      inc(km);
      mk[km]:=i;
    end;
  end;
  writeln(km);
  for i:=1 to km-1 do write(mk[i],' ');
  writeln(mk[km]);
  close(input);
  close(output);
end.