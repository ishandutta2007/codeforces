const fi = '';
      fo = '';
      e = round(1e9)+7;
var i, n, k: longint;
    cnt, cnt2: int64;
    p: array [1..8] of longint;

procedure EndProg;
begin
 close(input); close(output);
 halt;
end;

function Check(x: longint): boolean;
var v: longint;
    visited: array [1..8] of boolean;
begin
 //if (x = 1) and (p[x] = 1) then exit(true);
 fillchar(visited, sizeof(visited), false);
 visited[x]:=true;
 while true do
  begin
   x:=p[x];
   if x = 1 then exit(true)
   else if not visited[x] then visited[x]:=true
   else exit(false);
  end;
end;

procedure Generate(i: longint);
var j: longint;
begin
 if i > k then
  begin
   for j:=1 to k do
    if not Check(j) then exit;
   inc(cnt);
   exit;
  end;
 for j:=1 to k do
  begin
   p[i]:=j;
   Generate(i+1);
  end
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n, k);

 Generate(1);

 cnt2:=1;
 for i:=k+1 to n do cnt2:=(cnt2*(n-k)) mod e;

 writeln((cnt*cnt2) mod e);

 close(input); close(output);
end.