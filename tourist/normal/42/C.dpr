{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  a: array [0..9] of int64;
  k,i: longint;

procedure doit(c:char;p:longint);
var
  t: longint;
begin
  if p < 1 then inc(p,4);
  if p > 4 then dec(p,4);
  writeln(c,p);
  t:=p+1;
  if t > 4 then t:=1;
  if c = '/' then
  begin
    a[p]:=a[p] shr 1;
    a[t]:=a[t] shr 1;
  end else
  begin
    a[p]:=a[p]+1;
    a[t]:=a[t]+1;
  end;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(a[1],a[2],a[3],a[4]);
  while a[1]+a[2]+a[3]+a[4] > 4 do
  begin
    if a[1]+a[2]+a[3]+a[4] = 5 then
    begin
      for i:=1 to 4 do
        if a[i] = 2 then
        begin
          doit('+',i);
          break;
        end;
      continue;
    end;
    k:=1;
    for i:=2 to 4 do
      if a[i] > a[k] then k:=i;
    a[0]:=a[4]; a[5]:=a[1];
    i:=k;
    if a[i] and 1 = 0 then
    begin
      if a[i-1] and 1 = 0 then doit('/',i-1) else
      if a[i+1] and 1 = 0 then doit('/',i) else
      begin
        doit('+',i+1);
        doit('/',i);
      end;
    end else
    begin
      if a[i-1] and 1 = 0 then
      begin
        doit('+',i);
        doit('/',i-1);
      end else
      if a[i+1] and 1 = 0 then
      begin
        doit('+',i-1);
        doit('/',i);
      end else
      begin
        doit('+',i);
        doit('/',i);
      end;
    end;
  end;
//  close(input);
//  close(output);
end.