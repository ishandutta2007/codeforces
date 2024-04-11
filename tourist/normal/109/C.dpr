{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  n,m,i,qw,ii,e,j: longint;
  ans: int64;
  x,pred,last,ss,ff: array [0..400010] of longint;
  was,dd: array [0..400010] of boolean;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  m:=n-1;
  for i:=1 to m do
  begin
    read(ss[i],ff[i],qw);
    dd[i]:=True;
    while qw > 0 do
    begin
      if (qw mod 10 <> 4) and (qw mod 10 <> 7) then
      begin
        dd[i]:=False;
        break;
      end;
      qw:=qw div 10;
    end;
    ss[i+m]:=ff[i];
    ff[i+m]:=ss[i];
    dd[i+m]:=dd[i];
  end;
  fillchar(last,sizeof(last),0);
  for i:=1 to m+m do
    if not dd[i] then
    begin
      pred[i]:=last[ss[i]];
      last[ss[i]]:=i;
    end;
  fillchar(was,sizeof(was),False);
  ans:=int64(n)*(n-1)*(n-2);
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
      ans:=ans-int64(e)*(e-1)*(n-2)*2;
      ans:=ans+int64(e)*(e-1)*(e-2);
    end;
  writeln(ans);
  close(input);
  close(output);
end.