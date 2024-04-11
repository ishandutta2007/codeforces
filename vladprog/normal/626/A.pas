uses
  math;

var
  n,i,j,k,r,u,ans:longint;
  s:string;

begin
  readln(n);
  readln(s);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      begin
        if not odd(j-i)
          then continue;
        r:=0;
        u:=0;
        for k:=i to j do
          case s[k] of
            'U':inc(u);
            'D':dec(u);
            'R':inc(r);
            'L':dec(r)
          end;
        if (u=0)and(r=0)
          then inc(ans)
      end;
  writeln(ans)
end.