{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  kc,ii,n,m,k,i,k1,sum,e,j: longint;
  ss,ff,pred: array [0..2000010] of longint;
  last,x: array [0..1000010] of longint;
  was: array [0..1000010] of boolean;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m,k);
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
  fillchar(was,sizeof(was),False);
  k1:=0; sum:=2;
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
      if e > k then e:=k;
      if e = 1 then inc(k1)
      else inc(sum,e-2);
    end;
  if kc = 1 then writeln(0) else
  if k = 1 then writeln(kc-2) else
  if k1 <= sum then writeln(0)
  else writeln((k1-sum+1) div 2);
  close(input);
  close(output);
end.