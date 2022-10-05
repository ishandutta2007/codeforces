import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class TwoPizzas {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[] pleased = new int[512];
        for (int i = 0; i < n; i++) {
            int amt = scanner.nextInt();
            int mask = 0;
            for (int k = 0; k < amt; k++) {
                mask |= 1 << (scanner.nextInt() - 1);
            }
            for (int pizza = 0; pizza < 512; pizza++) {
                if ((mask & pizza) == mask) {
                    pleased[pizza]++;
                }
            }
        }
        Map<Integer, Pizza> pizzas1 = new HashMap<>();
        Map<Integer, Pizza> pizzas2 = new HashMap<>();
        for (int i = 1; i <= m; i++) {
            Pizza pizza = new Pizza(i, scanner.nextInt());
            int amt = scanner.nextInt();
            int mask = 0;
            for (int k = 0; k < amt; k++) {
                mask |= 1 << (scanner.nextInt() - 1);
            }
            if (!pizzas1.containsKey(mask)) {
                pizzas1.put(mask, pizza);
            } else if (pizza.cost < pizzas1.get(mask).cost) {
                pizzas2.put(mask, pizzas1.get(mask));
                pizzas1.put(mask, pizza);
            } else if (!pizzas2.containsKey(mask) || pizza.cost < pizzas2.get(mask).cost) {
                pizzas2.put(mask, pizza);
            }
        }
        int maxSatisfied = -1;
        int optimalCost = 0;
        int optimalPizza1 = 0;
        int optimalPizza2 = 0;
        for (int p1 = 0; p1 < 512; p1++) {
            if (!pizzas1.containsKey(p1)) {
                continue;
            }
            if (pizzas2.containsKey(p1)) {
                Pizza pizza1 = pizzas1.get(p1);
                Pizza pizza2 = pizzas2.get(p1);
                int satisfied = pleased[p1];
                if (satisfied > maxSatisfied || (satisfied == maxSatisfied && pizza1.cost + pizza2.cost < optimalCost)) {
                    maxSatisfied = satisfied;
                    optimalCost = pizza1.cost + pizza2.cost;
                    optimalPizza1 = pizza1.ix;
                    optimalPizza2 = pizza2.ix;
                }
            }
            for (int p2 = p1 + 1; p2 < 512; p2++) {
                if (pizzas1.containsKey(p2)) {
                    Pizza pizza1 = pizzas1.get(p1);
                    Pizza pizza2 = pizzas1.get(p2);
                    int satisfied = pleased[p1 | p2];
                    /*if (pizza1.ix == 2 && pizza2.ix == 3) {
                        System.out.println("satsified alpha = " + satisfied);
                    }
                    if (pizza1.ix == 1 && pizza2.ix == 3) {
                        System.out.println("satsified beta = " + satisfied);
                    }*/
                    if (satisfied > maxSatisfied || (satisfied == maxSatisfied && pizza1.cost + pizza2.cost < optimalCost)) {
                        maxSatisfied = satisfied;
                        optimalCost = pizza1.cost + pizza2.cost;
                        optimalPizza1 = pizza1.ix;
                        optimalPizza2 = pizza2.ix;
                    }
                }
            }
        }
        System.out.println(optimalPizza1 + " " + optimalPizza2);
    }

    static class Pizza {
        final int ix;
        final int cost;

        Pizza(int ix, int cost) {
            this.ix = ix;
            this.cost = cost;
        }
    }
}