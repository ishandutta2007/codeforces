import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

    public static void main(String[] args) throws IOException {
        new Main().run();
    }

    private void run() throws IOException {

        final long overflow = ((long) 1 << 32) - 1;
        long x = 0;

        final BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine());

        final Stack<Long> stack = new Stack<>();
        stack.add((long) 1);
        for (int i = 0; i < n; i++) {

            final String command = reader.readLine();

            if("add".equals(command)){

                x += stack.peek();
                if(x <= 0 || x > overflow){
                    System.out.println("OVERFLOW!!!");
                    return;
                }

            }else if("end".equals(command)){
                stack.pop();
            }else{
                stack.add(stack.peek() * Integer.parseInt(command.split("\\s")[1]));
            }

        }

        System.out.println(x);

    }

}