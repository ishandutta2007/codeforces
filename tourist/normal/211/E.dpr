{$R-,S-,Q-,I-,O+}
var
  ans,ii,kc,n,i,m,ver,e,j,sum: longint;
  c,ss,ff,pred,last,x: array [0..10010] of longint;
  can,res,was: array [0..5010] of boolean;
begin
  read(n);
  m:=n-1;
  for i:=1 to m do
  begin
    read(ss[i],ff[i]);
    ss[i+m]:=ff[i];
    ff[i+m]:=ss[i];
  end;
  fillchar(last,sizeof(last),0);
  for i:=1 to m+m do
  begin
    pred[i]:=last[ss[i]];
    last[ss[i]]:=i;
  end;
  fillchar(res,sizeof(res),False);
  for ver:=1 to n do
  begin
    fillchar(was,sizeof(was),False);
    was[ver]:=True;
    kc:=0;
    for ii:=1 to n do
      if not was[ii] then
      begin
        i:=1; e:=1;
        x[1]:=ii;
        was[ii]:=True;
        while i <= e do
        begin
          j:=last[x[i]];
          while j > 0 do
          begin
            if not was[ff[j]] then
            begin
              inc(e);
              x[e]:=ff[j];
              was[x[e]]:=True;
            end;
            j:=pred[j];
          end;
          inc(i);
        end;
        inc(kc);
        c[kc]:=e;
      end;
    fillchar(can,sizeof(can),False);
    can[0]:=True;
    sum:=0;
    for i:=1 to kc do
    begin
      for j:=sum downto 0 do
        if can[j] then can[j+c[i]]:=True;
      sum:=sum+c[i];
    end;
    for i:=0 to n do res[i]:=res[i] or can[i];
  end;
  ans:=0;
  for i:=1 to n-2 do
    if res[i] then inc(ans);
  writeln(ans);
  for i:=1 to n-2 do
    if res[i] then writeln(i,' ',n-1-i);
end.