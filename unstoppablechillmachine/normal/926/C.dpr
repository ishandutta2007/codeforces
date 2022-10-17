var 
   n, i, len, prev, need_len: longint;
   arr: array [1..100010] of longint; 
   t:boolean;
begin
t := true;
need_len := -1;
len := 0;
prev := 0;
readln(n);
for i:=1 to n do
begin
   read(arr[i]);
   if i = 1 then 
   begin
      prev := arr[i];
      len := 1;
   end
   else 
   begin
      if arr[i] = prev then inc(len)
      else 
      begin
         if need_len < 0 then 
         begin
            need_len := len;
            len := 1;
            prev := arr[i];
         end
         else
         begin
            if len <> need_len then t := false;
            len := 1;
            prev := arr[i];
         end
       end
    end
end;

if need_len < 0 then 
begin
  need_len := len;
  len := 1;
  prev := arr[i];
end
else
begin
  if len <> need_len then t := false;
  len := 1;
  prev := arr[i];
end;

if t = true then
begin
   write('Y');
   write('E');
   write('S');
end
else 
begin
   write('N');
   write('O');
end
end.