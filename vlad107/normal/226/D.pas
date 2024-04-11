var
  t1,t2:array[0..500500]of longint;
  a:array[0..1111,0..1111]of longint;
  ct1,ct2,i,j,n,m,sum:longint;
  found:boolean;

begin
  read(n,m);
  for i:=1 to n do begin
    for j:=1 to m do read(a[i][j]);
    readln;
  end;
  fillchar(t1,sizeof(t1),$0);
  fillchar(t2,sizeof(t2),$0);
  found:=true;
  while (found)do begin
    found:=false;
    for i:=1 to n do begin
      sum:=0;
      for j:=1 to m do inc(sum,a[i][j]);
      if (sum<0)then begin
        found:=true;
        t1[i]:=1-t1[i];
        for j:=1 to m do a[i][j]:=-a[i][j];
      end;
    end;
    for j:=1 to m do begin
      sum:=0;
      for i:=1 to n do inc(sum,a[i][j]);
      if (sum<0)then begin
        found:=true;
        t2[j]:=1-t2[j];
        for i:=1 to n do a[i][j]:=-a[i][j];
      end;
    end;
  end;
  ct1:=0;ct2:=0;
  for i:=1 to n do if (t1[i]=1)then inc(ct1);
  for i:=1 to m do if (t2[i]=1)then inc(ct2);
  write(ct1);
  for i:=1 to n do if (t1[i]=1)then write(' ',i);
  writeln;
  write(ct2);
  for i:=1 to m do if (t2[i]=1)then write(' ',i);
  writeln;
end.