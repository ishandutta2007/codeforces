{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  n,k,xc,yc,t,i,j,q,s,min,ki,kj,z: longint;
  v: array [0..110,0..110,0..110] of longint;
  a: array [0..110,0..110] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,k);
  xc:=(k+1) div 2;
  yc:=xc;
  for t:=1 to k do
    for i:=1 to k do
      for j:=1 to k-t+1 do
      begin
        v[t,i,j]:=0;
        for z:=j to j+t-1 do inc(v[t,i,j],abs(i-xc)+abs(z-yc));
      end;
  fillchar(a,sizeof(a),0);
  for q:=1 to n do
  begin
    read(t);
    min:=maxlongint;
    ki:=0; kj:=0;
    for i:=1 to k do
    begin
      s:=0;
      for j:=1 to t do s:=s+a[i,j];
      for j:=t to k do
      begin
        if s = 0 then
          if v[t,i,j-t+1] < min then
          begin
            min:=v[t,i,j-t+1];
            ki:=i;
            kj:=j-t+1;
          end;
        s:=s+a[i,j+1]-a[i,j-t+1];
      end;
    end;
    if min = maxlongint then writeln(-1) else
    begin
      writeln(ki,' ',kj,' ',kj+t-1);
      for j:=kj to kj+t-1 do a[ki,j]:=1;
    end;
  end;
  close(input);
  close(output);
end.