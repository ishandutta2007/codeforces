{$R-,S-,Q-,I-,O+}
var
  q,n,i,j,kr,cur,ans,best,st: longint;
  dd: boolean;
  kg,bad,c: array [0..210] of longint;
  ok: array [0..210] of boolean;
  g: array [0..210,0..210] of longint;
begin
  read(n);
  for i:=1 to n do read(c[i]);
  fillchar(g,sizeof(g),0);
  for i:=1 to n do
  begin
    read(kg[i]);
    for j:=1 to kg[i] do
    begin
      read(q);
      g[q,i]:=1;
    end;
  end;
  best:=maxlongint;
  for st:=1 to 3 do
  begin
    for i:=1 to n do bad[i]:=kg[i];
    for i:=1 to n do ok[i]:=False;
    cur:=st; kr:=0; ans:=0;
    while kr < n do
    begin
      dd:=True;
      while dd do
      begin
        dd:=False;
        for i:=1 to n do
          if (not ok[i]) and (c[i] = cur) and (bad[i] = 0) then
          begin
            dd:=True;
            ok[i]:=True;
            inc(kr);
            inc(ans);
            for j:=1 to n do
              if g[i,j] = 1 then dec(bad[j]);
          end;
      end;
      if kr = n then break;
      cur:=cur mod 3+1;
      inc(ans);
    end;
    if ans < best then best:=ans;
  end;
  writeln(best);
end.