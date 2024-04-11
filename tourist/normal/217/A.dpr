{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,i,ii,e,j,ans: longint;
  q,x,y: array [0..11111] of longint;
  was: array [0..11111] of boolean;
begin  
  read(n);
  for i:=1 to n do read(x[i],y[i]);
  fillchar(was,sizeof(was),False);
  ans:=-1;
  for ii:=1 to n do
    if not was[ii] then
    begin
      inc(ans);
      i:=1; e:=1;
      q[1]:=ii;
      was[ii]:=True;
      while i <= e do
      begin
        for j:=1 to n do
          if not was[j] then
            if (x[j] = x[q[i]]) or (y[j] = y[q[i]]) then
            begin
              inc(e);
              q[e]:=j;
              was[j]:=True;
            end;
        inc(i);
      end;
    end;
  writeln(ans);
end.