{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  n,i,q,x,y: longint;
  a: array [0..100010] of longint;

function check(s,f:longint):boolean;
var
  i: longint;
begin
  if s = f then check:=True else
  if (a[s] = 0) or (a[s+1] = 0) then
  begin
    for i:=s+1 to f do
      if a[i] <> 0 then
      begin
        check:=False;
        exit;
      end;
    check:=True;
  end else
  begin
    for i:=s+1 to f-1 do
      if a[i]*a[i] <> a[i-1]*a[i+1] then
      begin
        check:=False;
        exit;
      end;
    check:=True;
  end;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do read(a[i]);
  if check(1,n) then writeln(0) else
  if check(2,n) then writeln(1) else
  begin
    q:=a[2]; a[2]:=a[1];
    if check(2,n) then writeln(1) else
    begin
      a[2]:=q;
      if (a[1] = 0) or (a[2] = 0) then
      begin
        q:=0;
        for i:=2 to n do
          if a[i] <> 0 then inc(q);
        if q <= 1 then writeln(1)
        else writeln(2);
      end else
      begin
        x:=1; y:=2;
        q:=0;
        for i:=3 to n do
          if a[i]*a[x] <> a[y]*a[y] then inc(q) else
          begin
            x:=y;
            y:=i;
          end;
        if q <= 1 then writeln(1)
        else writeln(2);
      end;
    end;
  end;
  close(input);
  close(output);
end.