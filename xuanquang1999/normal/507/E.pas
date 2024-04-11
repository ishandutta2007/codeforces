const fi = '';
      fo = '';
      maxN = 100000;
      maxM = 100000;
      maxC = 1000000000;
var u, v, c: array [1..maxM] of longint;
    ke, keC, id: array [1..maxM*2] of longint;
    Queue, dau, d, f, tracei, traceu: array [1..maxN] of longint;
    n, m, first, last, count: longint;

procedure Enter;
var i: longint;
begin
 readln(n, m);
 for i:=1 to m do
  begin
   readln(u[i], v[i], c[i]);
   inc(dau[u[i]]); inc(dau[v[i]]);
   if c[i] = 1 then inc(count);
  end;
 for i:=2 to n+1 do dau[i]:=dau[i-1]+dau[i];
 for i:=1 to m do
  begin
   ke[dau[u[i]]]:=v[i]; keC[dau[u[i]]]:=c[i]; id[dau[u[i]]]:=dau[v[i]]; dec(dau[u[i]]);
   ke[dau[v[i]]]:=u[i]; keC[dau[v[i]]]:=c[i]; id[dau[v[i]]]:=dau[u[i]]+1; dec(dau[v[i]]);
  end;
end;

procedure Push(v: longint);
begin
 inc(last); Queue[last]:=v;
end;

function Pop: longint;
begin
 Pop:=Queue[first]; inc(first);
end;

procedure Work;
var i, u, v, c: longint;
begin
 for u:=1 to n do d[u]:=maxC;
 first:=1; last:=0;
 Push(1);
 d[1]:=0;
 f[1]:=0;
 while first <= last do
  begin
   u:=Pop;
   for i:=dau[u]+1 to dau[u+1] do
    begin
     v:=ke[i];
     c:=1-keC[i]+f[u];
     if (d[v] > d[u]+1) or ((d[v] = d[u]+1) and (f[v] > c)) then
      begin
       if d[v] > d[u]+1 then
        begin
         Push(v);
         d[v]:=d[u]+1;
        end;
       f[v]:=c;
       tracei[v]:=i;
       traceu[v]:=u;
      end;
    end;
  end;
end;

procedure Answer;
var i, u, v: longint;
    free: array [1..maxM*2] of boolean;
begin
 fillchar(free, sizeof(free), true);
 writeln(count-d[n]+2*f[n]);
 v:=n;
 while v <> 1 do
  begin
   i:=tracei[v];
   u:=traceu[v];
   if keC[i] = 0 then writeln(u, ' ', v, ' ', 1);
   free[i]:=false; free[id[i]]:=false;
   v:=u;
  end;
 for u:=1 to n do
  for i:=dau[u]+1 to dau[u+1] do
   if (keC[i] = 1) and free[i] then
    begin
     writeln(u, ' ', ke[i], ' ', 0);
     free[id[i]]:=false;
    end;
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 Work;
 Answer;

 close(input); close(output);
end.