{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  f: array [0..44,0..66,0..66] of longint;
  kb: array [0..66] of longint;
  ft,tmp,n,m,i,t0,t1,t,tk,ans: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m);
  if n < m then begin tmp:=n; n:=m; m:=tmp; end;
  kb[0]:=0;
  for t:=1 to 1 shl m-1 do kb[t]:=kb[t and (t-1)]+1;
  fillchar(f,sizeof(f),50);
  f[1,0,0]:=0;
  for i:=1 to n do
    for t0:=0 to 1 shl m-1 do
      for t1:=0 to 1 shl m-1 do
        if f[i,t0,t1] < 1e6 then
        begin
          for t:=0 to 1 shl m-1 do
            if (i = 1) or (t0 or t = 1 shl m-1) then
            begin
              tk:=t1 or t or (t shr 1) or ((t shl 1) and (1 shl m-1));
              ft:=f[i,t0,t1]+kb[t];
              if ft < f[i+1,tk,t] then f[i+1,tk,t]:=ft;
            end;
        end;
  ans:=maxlongint;
  for t:=0 to 1 shl m-1 do
    if f[n+1,1 shl m-1,t] < ans then
      ans:=f[n+1,1 shl m-1,t];
  writeln(n*m-ans);
  close(input);
  close(output);
end.