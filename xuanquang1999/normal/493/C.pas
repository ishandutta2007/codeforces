const fi = '';
      fo = '';
      maxN = 200000+10;
var a, b: array [1..maxN] of longint;
    d, id, f1, f2: array [0..maxN*2] of longint;
    na, nb, n, ansA, ansB: longint;

procedure Enter;
var i: longint;
begin
 readln(na);
 for i:=1 to na do read(a[i]);
 readln(nb);
 for i:=1 to nb do read(b[i]);
end;

procedure Swap(var a, b: longint);
var t: longint;
begin
 t:=a; a:=b; b:=t;
end;

procedure QSortID(l, r: longint);
var i, j, p1, p2: longint;
begin
 if l >= r then exit;
 i:=l; j:=r;
 p1:=d[(i+j) div 2];
 p2:=id[(i+j) div 2];
 while i <= j do
  begin
   while (d[i] < p1) or ((d[i] = p1) and (id[i] < p2)) do inc(i);
   while (d[j] > p1) or ((d[j] = p1) and (id[j] > p2)) do dec(j);
   if i <= j then
    begin
     Swap(d[i], d[j]);
     Swap(id[i], id[j]);
     inc(i); dec(j);
    end;
  end;
 QSortID(l, j); QSortID(i, r);
end;

procedure Work;
var i, count1, count2: longint;
begin
 n:=na + nb;
 for i:=1 to na do
  begin
   d[i]:=a[i];
   id[i]:=1;
  end;
 for i:=na+1 to n do
  begin
   d[i]:=b[i-na];
   id[i]:=2;
  end;

 QSortID(1, n);

 for i:=n downto 1 do
  begin
   f1[i]:=f1[i+1];
   f2[i]:=f2[i+1];
   if id[i] = 1 then inc(f1[i]) else inc(f2[i]);
  end;
 for i:=1 to n do
  begin
   f1[i]:=f1[i+1];
   f2[i]:=f2[i+1];
  end;

 ansA:=-maxlongint; ansB:=0;
 for i:=1 to n do
  begin
   count1:=(f1[i])*3 + (na-(f1[i]))*2;
   count2:=(f2[i])*3 + (nb-(f2[i]))*2;
   if (count1-count2 > ansA-ansB) or ((count1-count2 = ansA-ansB) and (count1 > ansA)) then
    begin
     ansA:=count1;
     ansB:=count2;
    end;
  end;

 count1:=na*3;
 count2:=nb*3;
 if (count1-count2 > ansA-ansB) or ((count1-count2 = ansA-ansB) and (count1 > ansA)) then
  begin
   ansA:=count1;
   ansB:=count2;
  end;
end;

procedure Answer;
begin
 writeln(ansA, ':', ansB);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 Work;
 Answer;

 close(input); close(output);
end.