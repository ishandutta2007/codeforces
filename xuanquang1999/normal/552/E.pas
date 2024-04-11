uses math;
const fi = '';
      fo = '';
      maxN = 5001;
var s, t: string;
    i, j, n, k, top: longint;
    stack: array [1..maxN] of char;
    stackI: array [1..maxN] of int64;
    d: array [1..maxN] of longint;
    visited: array [1..maxN] of boolean;
    ans: int64;

procedure Push(c: char);
begin
 inc(top); stack[top]:=c;
end;

function Pop: char;
begin
 Pop:=stack[top]; dec(top);
end;

function Calculate(s: string): int64;
var i, j: longint;
    ex: string;
begin
 top:=0; ex:='';
 for i:=1 to length(s) do
  case s[i] of
   '*', '(': Push(s[i]);
   ')':
    begin
     while (top > 0) and (stack[top] <> '(') do ex:=ex+Pop;
     Pop;
    end;
   '+':
   begin
    while (top > 0) and (stack[top] = '*') do ex:=ex+Pop;
    Push(s[i]);
   end
   else ex:=ex+s[i];
  end;
 while (top > 0) do ex:=ex+Pop;

 for i:=1 to length(ex) do
  case ex[i] of
   '+':
   begin
    stackI[top-1]:=stackI[top-1]+stackI[top];
    dec(top);
   end;
   '*':
   begin
    stackI[top-1]:=stackI[top-1]*stackI[top];
    dec(top);
   end;
   else begin
    inc(top);
    stackI[top]:=ord(ex[i])-48;
   end
  end;

 exit(stackI[top]);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(s);
 n:=length(s);

 d[1]:=1; k:=1;
 for i:=1 to n do
  if s[i] = '*' then
   begin
    if not visited[i-1] then
     begin
      inc(k);
      d[k]:=i-1;
      visited[i-1]:=true;
     end;
    if not visited[i+1] then
     begin
      inc(k);
      d[k]:=i+1;
      visited[i+1]:=true;
     end;
   end;
 if not visited[n] then
  begin
   visited[n]:=true;
   inc(k); d[k]:=n;
  end;
 for i:=1 to k do
  for j:=i+1 to k do
   begin
    t:=s;
    insert(')', t, d[j]+1);
    insert('(', t, d[i]);
    ans:=max(ans, Calculate(t));
   end;

 writeln(ans);

 close(input); close(output);
end.