const fi = '';
      fo = '';
      maxN = 100000;
var n, m, k: longint;
    ans: Qword;
    a, prev, curpos, after: array [1..maxN] of longint;

procedure Enter;
var i: longint;
begin
 readln(n, m, k);
 for i:=1 to n do read(a[i]);

 for i:=1 to n do
  begin
   if i = 1 then prev[a[i]]:=-1
   else
    begin
     prev[a[i]]:=a[i-1];
     after[a[i-1]]:=a[i];
    end;
   curpos[a[i]]:=i;
  end;
 after[a[n]]:=-1;
end;

procedure Work;
var i, x, b, a: longint;
begin
 for i:=1 to m do
  begin
   read(x);
   ans:=ans + (curpos[x]-1) div k + 1;
   b:=prev[x];
   if b <> -1 then
    begin
     a:=after[x];
     inc(curpos[b]);
     dec(curpos[x]);
     prev[x]:=prev[b];
     after[x]:=b;
     if a <> -1 then prev[a]:=b;
     if prev[b] <> -1 then after[prev[b]]:=x;
     after[b]:=a;
     prev[b]:=x;
    end;
  end;
end;

procedure Answer;
begin
 writeln(ans);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 Work;
 Answer;

 close(input); close(output);
end.