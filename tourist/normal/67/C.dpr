{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  f: array [0..4010,0..4010] of longint;
  last: array ['a'..'z'] of longint;
  pa,pb: array [0..4010,'a'..'z'] of longint;
  ch: char;
  ii,jj,ft,ti,td,tr,te,n,m,i,j: longint;
  a,b: ansistring;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(ti,td,tr,te);
  readln(a);
  readln(b);
  n:=length(a);
  m:=length(b);
  fillchar(last,sizeof(last),0);
  for i:=1 to n do
  begin
    last[a[i]]:=i;
    for ch:='a' to 'z' do pa[i,ch]:=last[ch];
  end;
  fillchar(last,sizeof(last),0);
  for i:=1 to m do
  begin
    last[b[i]]:=i;
    for ch:='a' to 'z' do pb[i,ch]:=last[ch];
  end;
  for i:=0 to n do
    for j:=0 to m do
      if i+j = 0 then f[i,j]:=0 else
      begin
        f[i,j]:=round(1e9);
        if i > 0 then
          if f[i-1,j]+td < f[i,j] then f[i,j]:=f[i-1,j]+td;
        if j > 0 then
          if f[i,j-1]+ti < f[i,j] then f[i,j]:=f[i,j-1]+ti;
        if (i > 0) and (j > 0) then
          if a[i] = b[j] then
          begin
            if f[i-1,j-1] < f[i,j] then f[i,j]:=f[i-1,j-1];
          end else
            if f[i-1,j-1]+tr < f[i,j] then f[i,j]:=f[i-1,j-1]+tr;
        if (i > 1) and (j > 1) then
        begin
          ii:=pa[i-1,b[j]];
          jj:=pb[j-1,a[i]];
          if (ii > 0) and (jj > 0) then
          begin
            ft:=f[ii-1,jj-1]+td*(i-1-ii)+ti*(j-1-jj)+te;
            if ft < f[i,j] then f[i,j]:=ft;
          end;
        end;
      end;
  writeln(f[n,m]);
  close(input);
  close(output);
end.