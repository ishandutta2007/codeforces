{$r-,q-,s-,i-,o+}
var
  n,m,i,j,kt,aa,bb,cc,res:longint;
  o1,o2,o3,x,y:array[0..500500]of longint;
  a:array[0..1111,0..1111]of longint;
  procedure solve(q1,q2,q3:longint);
    var
      j,q,sum,i:longint;
    begin
      for i:=1 to kt do
        if (o1[i]=q1)and(o2[i]=q2)and(o3[i]=q3)then exit;

      inc(kt);o1[i]:=q1;o2[i]:=q2;o3[i]:=q3;

      for i:=1 to n do
        for j:=i+1 to n-1 do begin
          sum:=0;
          for q:=1 to i do inc(sum,y[q]);
          if (sum<>q1)then continue;

          sum:=0;
          for q:=i+1 to j do inc(sum,y[q]);
          if (sum<>q2)then continue;

          sum:=0;
          for q:=j+1 to n do inc(sum,y[q]);
          if (sum<>q3)then continue;
          inc(res);
        end;

      for i:=1 to m do
        for j:=i+1 to m-1 do begin
          sum:=0;
          for q:=1 to i do inc(sum,x[q]);
          if (sum<>q1)then continue;

          sum:=0;
          for q:=i+1 to j do inc(sum,x[q]);
          if (sum<>q2)then continue;

          sum:=0;
          for q:=j+1 to m do inc(sum,x[q]);
          if (sum<>q3)then continue;
          inc(res);
        end;

    end;

begin
  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);
  read(n,m);

  for i:=1 to n do for j:=1 to m do read(a[i][j]);

  for j:=1 to m do begin
    x[j]:=0;
    for i:=1 to n do inc(x[j],a[i][j]);
  end;

  for i:=1 to n do begin
    y[i]:=0;
    for j:=1 to m do inc(y[i],a[i][j]);
  end;

  read(aa,bb,cc);

  kt:=0;
  res:=0;
  solve(aa,bb,cc);
  solve(aa,cc,bb);
  solve(bb,aa,cc);
  solve(bb,cc,aa);
  solve(cc,aa,bb);
  solve(cc,bb,aa);
  writeln(res);
  close(output);close(input);
end.