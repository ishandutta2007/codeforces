var
  n,i,j,kf,cf,ka:longint;
  l,r,a:array[1..5555] of longint;
  f:array[1..5010,1..5010] of longint;

  function cross(i,j:longint):boolean;
   begin
     if (l[i]>l[j]) and (l[i]<r[j]) then cross:=true else
     if (r[i]>l[j]) and (r[i]<r[j]) then cross:=true else
     if (l[j]>l[i]) and (l[j]<r[i]) then cross:=true else
     if (r[j]>l[i]) and (r[j]<r[i]) then cross:=true else
     cross:=false;
   end;

begin
  read(n);
  for i:=1 to n do read(l[i],r[i]);
  fillchar(f,sizeof(f),$0);
  kf:=0;
  for i:=1 to n do 
    for j:=1 to n do 
      if (i<>j) and (cross(i,j))
        then begin
          f[i][j]:=1;
          inc(kf);
        end;
  ka:=0;
  for i:=1 to n do begin
    cf:=0;
    for j:=1 to n do inc(cf,f[i][j]);
    if (cf+cf=kf)
      then begin
        inc(ka);
        a[ka]:=i;
      end;
  end;
  writeln(ka);
  for i:=1 to ka do 
    write(a[i],' ');
end.