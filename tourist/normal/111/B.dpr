{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  n,i,j,m,d,p: longint;
  last,ans,x,y: array [0..100010] of longint;
  a,b,pred: array [0..13131313] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do read(x[i],y[i]);
  fillchar(last,sizeof(last),0);
  m:=0;
  for i:=n downto 1 do
    for j:=1 to 400 do
      if j*j > x[i] then break else
      if x[i] mod j = 0 then
      begin
        inc(m);
        a[m]:=j;
        b[m]:=i;
        pred[m]:=last[j];
        last[j]:=m;
        if j*j < x[i] then
        begin
          inc(m);
          a[m]:=x[i] div j;
          b[m]:=i;
          pred[m]:=last[a[m]];
          last[a[m]]:=m;
        end;
      end;
  fillchar(ans,sizeof(ans),0);
  for d:=1 to 100000 do
  begin
    p:=0;
    j:=last[d];
    while j > 0 do
    begin
      if b[j]-y[b[j]] > p then inc(ans[b[j]]);
      p:=b[j];
      j:=pred[j];
    end;
  end;
  for i:=1 to n do writeln(ans[i]);
  close(input);
  close(output);
end.