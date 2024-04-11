uses math;
const fi = '';
      fo = '';
      maxN = 100000;
      maxX = 1000000;
var i, n, l, r, minS, ansL, ansR, reqb: longint;
    a: array [1..maxN] of longint;
    cnt: array [1..maxX] of longint;
    cnt1: longint;

procedure EndProg;
begin
 close(input); close(output);
 halt;
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 for i:=1 to n do read(a[i]);

 for i:=1 to n do inc(cnt[a[i]]);
 for i:=1 to maxX do reqb:=max(reqb, cnt[i]);

 fillchar(cnt, sizeof(cnt), 0);
 r:=0; minS:=maxN+1; cnt1:=0;
 for l:=1 to n do
  begin
   while (r <= n) and (cnt1 = 0) do
    begin
     inc(r);
     if r = n+1 then
      begin
       writeln(ansL, ' ', ansR);
       EndProg;
      end;
     inc(cnt[a[r]]);
     if cnt[a[r]] = reqb then inc(cnt1);
    end;
   if r-l+1 < minS then
    begin
     minS:=r-l+1; 
     ansL:=l;
     ansR:=r;
    end;
   dec(cnt[a[l]]);
   if cnt[a[l]] = reqb-1 then dec(cnt1);
  end;

 writeln(ansL, ' ', ansR);

 close(input); close(output);
end.