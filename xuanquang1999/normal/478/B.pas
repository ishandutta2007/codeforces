var m, n: int64;
    n1, p1, n2, p2, ansMin, ansMax: int64;

function PairNum(x: int64): int64;
begin
 exit((x*(x-1)) div 2);
end;

function Count(n1, p1, n2, p2: int64): int64;
begin
 exit(n1*PairNum(p1) + n2*PairNum(p2));
end;

begin
 readln(n, m);

 //minimum case
 n1:=n mod m;
 n2:=m-n1;
 p2:=n div m;
 p1:=p2+1;
 ansMin:=Count(n1, p1, n2, p2);

 //maximum case
 n1:=m-1;
 p1:=1;
 n2:=1;
 p2:=n-n1;
 ansMax:=Count(n1, p1, n2, p2);

 writeln(ansMin, ' ', ansMax);
end.