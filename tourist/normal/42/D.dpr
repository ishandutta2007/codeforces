{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,i,j,c: longint;
  a: array [0..22,0..22] of longint;
  ok: boolean;
  was: array [0..100010] of boolean;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  fillchar(a,sizeof(a),0);
  a[1,2]:=1; a[1,3]:=2;
  a[2,1]:=1; a[2,3]:=3;
  a[3,1]:=2; a[3,2]:=3;
  fillchar(was,sizeof(was),False);
  was[1]:=True; was[2]:=True; was[3]:=True;
  for i:=4 to n do
  begin
    c:=1;
    while True do
    begin
      ok:=True;
      for j:=1 to i-1 do
        if was[a[1,j]+c] then
        begin
          ok:=False;
          break;
        end;
      if ok then break;
      inc(c);
    end;
    for j:=1 to i-1 do
    begin
      a[i,j]:=a[1,j]+c;
      a[j,i]:=a[i,j];
      was[a[i,j]]:=True;
    end;
  end;
  for i:=1 to n do
  begin
    for j:=1 to n-1 do write(a[i,j],' ');
    writeln(a[i,n]);
  end;
  close(input);
  close(output);
end.