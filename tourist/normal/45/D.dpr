{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,i,j,tmp,ii: longint;
  ok: boolean;
  a,b,num,ans: array [0..1010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do read(a[i],b[i]);
  for i:=1 to n do num[i]:=i;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if b[num[i]] > b[num[j]] then
      begin
        tmp:=num[i];
        num[i]:=num[j];
        num[j]:=tmp;
      end;
  for i:=1 to n do ans[i]:=0;
  for ii:=1 to n do
  begin
    i:=num[ii];
    while a[i] <= b[i] do
    begin
      ok:=True;
      for j:=1 to n do
        if ans[j] = a[i] then
        begin
          ok:=False;
          break;
        end;
      if ok then break;
      inc(a[i]);
    end;
    ans[i]:=a[i];
  end;
  for i:=1 to n-1 do write(ans[i],' ');
  writeln(ans[n]);
  close(input);
  close(output);
end.