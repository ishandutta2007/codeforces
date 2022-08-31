{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,m,k,i,j,tmp: longint;
  ch: char;
  ok: boolean;
  ss: ansistring;
  q: array [0..1111] of longint;
  name: array [0..1111] of ansistring;
  _k: double;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(n,m,_k);
  k:=round(_k*100);
  j:=0;
  for i:=1 to n do
  begin
    read(ch);
    while not (ch in ['a'..'z']) do read(ch);
    name[i]:='';
    while ch in ['a'..'z'] do
    begin
      name[i]:=name[i]+ch;
      read(ch);
    end;
    read(q[i]);
    q[i]:=q[i]*k div 100;
    if q[i] >= 100 then
    begin
      inc(j);
      name[j]:=name[i];
      q[j]:=q[i];
    end;
  end;
  n:=j;
  for i:=1 to m do
  begin
    read(ch);
    while not (ch in ['a'..'z']) do read(ch);
    ss:='';
    while ch in ['a'..'z'] do
    begin
      ss:=ss+ch;
      read(ch);
    end;
    ok:=False;
    for j:=1 to n do
      if name[j] = ss then
      begin
        ok:=True;
        break;
      end;
    if not ok then
    begin
      inc(n);
      name[n]:=ss;
      q[n]:=0;
    end;
  end;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if name[i] > name[j] then
      begin
        ss:=name[i]; name[i]:=name[j]; name[j]:=ss;
        tmp:=q[i]; q[i]:=q[j]; q[j]:=tmp;
      end;
  writeln(n);
  for i:=1 to n do writeln(name[i],' ',q[i]);
  close(input);
  close(output);
end.