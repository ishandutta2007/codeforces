{$R+,S+,Q+,I+,O-}
var
  sl: ansistring;
  ch: char;
  nam: array [0..1010] of ansistring;
  tt,qq,sum,max,it: array [0..1010] of longint;
  q,n,m,mx,mi,km,i,j,t: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  m:=0;
  for i:=1 to n do
  begin
    read(ch);
    while not (ch in ['a'..'z']) do read(ch);
    sl:='';
    while ch in ['a'..'z'] do
    begin
      sl:=sl+ch;
      read(ch);
    end;
    t:=0;
    for j:=1 to m do
      if nam[j] = sl then
      begin
        t:=j;
        break;
      end;
    if t = 0 then
    begin
      inc(m);
      nam[m]:=sl;
      sum[m]:=0;
      max[m]:=0;
      it[m]:=0;
      t:=m;
    end;
    read(q);
    tt[i]:=t;
    qq[i]:=q;
    inc(sum[t],q);
  end;
  fillchar(max,sizeof(max),0);
  for i:=1 to n do
  begin
    inc(max[tt[i]],qq[i]);
    if (max[tt[i]] >= sum[tt[i]]) and (it[tt[i]] = 0) then it[tt[i]]:=i;
  end;
  mx:=0; mi:=0; km:=0;
  for i:=1 to m do
    if (sum[i] > mx) or (sum[i] = mx) and (it[i] < mi) then
    begin
      mx:=sum[i];
      mi:=it[i];
      km:=i;
    end;
  writeln(nam[km]);
  close(input);
  close(output);
end.