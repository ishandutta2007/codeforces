{$macro+}
{$define free}

{$ifdef free}
uses math;
{$endif}

const
  inf=1000;
  s=100;

type
  work=record
    n,m,sum:longint;
    a:array[1..s,1..s]of longint;
    r,c:array[1..s]of longint;
  end;

var
  i,j,k:longint;
  w1,w2:work;

begin
  read(w1.n,w1.m);
  w2.n:=w1.m;
  w2.m:=w1.n;
  for i:=1 to w1.n do
    for j:=1 to w1.m do
      begin
        read(w1.a[i,j]);
        w2.a[j,i]:=w1.a[i,j]
      end;
  with w1 do
    begin
      sum:=0;
      for i:=1 to n do
        begin
          r[i]:=inf;
          for j:=1 to m do
            r[i]:=min(r[i],a[i,j]);
          inc(sum,r[i]);
          for j:=1 to m do
            dec(a[i,j],r[i])
        end;
      for j:=1 to m do
        begin
          c[j]:=inf;
          for i:=1 to n do
            c[j]:=min(c[j],a[i,j]);
          inc(sum,c[j]);
          for i:=1 to n do
            dec(a[i,j],c[j])
        end;
      for i:=1 to n do
        for j:=1 to m do
          if a[i,j]<>0 then
            begin
              writeln(-1);
              halt
            end;
    end;
  with w2 do
    begin
      sum:=0;
      for i:=1 to n do
        begin
          r[i]:=inf;
          for j:=1 to m do
            r[i]:=min(r[i],a[i,j]);
          inc(sum,r[i]);
          for j:=1 to m do
            dec(a[i,j],r[i])
        end;
      for j:=1 to m do
        begin
          c[j]:=inf;
          for i:=1 to n do
            c[j]:=min(c[j],a[i,j]);
          inc(sum,c[j]);
          for i:=1 to n do
            dec(a[i,j],c[j])
        end;
    end;
  if w1.sum<=w2.sum
    then with w1 do
      begin
        writeln(sum);
        for i:=1 to n do
          for k:=1 to r[i] do
            writeln('row ',i);
        for j:=1 to m do
          for k:=1 to c[j] do
            writeln('col ',j);
      end
    else with w2 do
      begin
        writeln(sum);
        for i:=1 to n do
          for k:=1 to r[i] do
            writeln('col ',i);
        for j:=1 to m do
          for k:=1 to c[j] do
            writeln('row ',j);
      end
end.